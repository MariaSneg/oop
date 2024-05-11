#include "compound.h"
#include "sphere.h"
#include "parallelepiped.h"
#include "cone.h"
#include "cylinder.h"
#include <string>
#include<map>
#include <iostream>

const std::map<std::string, int> commands
{
    { "Sphere", 1 },
    { "Parallelepiped", 2 },
    { "Cone", 3 },
    { "Cylinder", 4 },
    { "Compound", 5 }
};


CCompound::CCompound(std::istream& in, std::ostream& out)
    : CBody("Compound", in, out)
{
}

void CCompound::AddChildBody(std::unique_ptr<CBody>& child)
{
    child->ReadProperties();
    m_bodies.push_back(std::move(child));
}

double CCompound::GetVolume() const
{
    double volume = 0;
    for (const auto& body : m_bodies)
    {
        volume += body->GetVolume();
    }
    return volume;
}

double CCompound::GetDensity() const
{
    if (m_bodies.empty())
    {
        return 0.0;
    }
    double density = 0;
    for (const auto& body : m_bodies)
    {
        density += body->GetDensity();
    }
    return density / (double)m_bodies.size();
}

void CCompound::AppendProperties(std::ostream& strm) const
{
    for (const auto& body : m_bodies)
    {
        strm << "\t" << body->ToString() << std::endl;
    }
}

void CCompound::AddProperties()
{
    m_output << "Enter bodies. To exit enter \"...\"" << std::endl;
    std::string cmd;
    while (m_input >> cmd)
    {
        if (cmd == "...")
        {
            break;
        }
        if (commands.find(cmd) == commands.end())
        {
            m_output << "Unknown body" << std::endl;;
            continue;
        }
        std::unique_ptr<CBody> s;
        switch (commands.at(cmd))
        {
        case 1:
            s = std::make_unique<CSphere>(m_input, m_output);
            AddChildBody(s);
            break;
        case 2:
            s = std::make_unique<CParallelepiped>(m_input, m_output);
            AddChildBody(s);
            break;
        case 3:
            s = std::make_unique<CCone>(m_input, m_output);
            AddChildBody(s);
            break;
        case 4:
            s = std::make_unique<CCylinder>(m_input, m_output);
            AddChildBody(s);
            break;
        case 5:
            s = std::make_unique<CCompound>(m_input, m_output);
            AddChildBody(s);
            break;
        }
        m_output << "Next body:" << std::endl;
    }
}
