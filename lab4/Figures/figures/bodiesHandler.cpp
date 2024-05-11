#include "bodiesHandler.h"
#include "sphere.h"
#include "parallelepiped.h"
#include "cone.h"
#include "cylinder.h"
#include "compound.h"
#include <iostream>
#include <map>

CBodiesHandler::CBodiesHandler(std::istream& input, std::ostream& output)
    : m_input(input)
    , m_output(output)
{
}

const std::map<std::string, int> Commands
{
    { "Sphere", 1 },
    { "Parallelepiped", 2 },
    { "Cone", 3 },
    { "Cylinder", 4 },
    { "Compound", 5 }
};

void CBodiesHandler::HandleBody(std::string cmd)
{
    std::unique_ptr<CBody> s;
    if (Commands.find(cmd) == Commands.end())
    {
        m_output << "Unknown body" << std::endl;
        return;
    }
    switch (Commands.at(cmd))
    {
    case 1:
        s = std::make_unique<CSphere>(std::cin, std::cout);
        break;
    case 2:
        s = std::make_unique<CParallelepiped>(std::cin, std::cout);
        break;
    case 3:
        s = std::make_unique<CCone>(std::cin, std::cout);
        break;
    case 4:
        s = std::make_unique<CCylinder>(std::cin, std::cout);
        break;
    case 5:
        s = std::make_unique<CCompound>(std::cin, std::cout);
        break;
    }
    s->ReadProperties();
    m_bodies.push_back(std::move(s));
}

void CBodiesHandler::PrintBodies() const
{
    for (const auto& body : m_bodies)
    {
        m_output << body->ToString() << std::endl;
    }
}

double CBodiesHandler::MinMassInWater() const
{
    if (m_bodies.empty())
    {
        return 0.0;
    }
    auto result = std::min_element(m_bodies.begin(), m_bodies.end(),
        [](const auto& body, const auto& nextBody)
        {
            return body->GetMassInWater() > nextBody->GetMassInWater();
        });
    return result->get()->GetMassInWater();
}

double CBodiesHandler::MaxMass() const
{
    if (m_bodies.empty())
    {
        return 0.0;
    }
    auto result = std::max_element(m_bodies.begin(), m_bodies.end(),
        [](const auto& body, const auto& nextBody)
        {
            return body->GetMass() < nextBody->GetMass();
        });
    return result->get()->GetMass();
}


