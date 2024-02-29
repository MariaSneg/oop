chcp 1251
 
SET MyProgram="%~1"
 
if %MyProgram% == "" (
	echo Please specify path to program
	exit /B 1
)

rem "$(ProjectDir)Tests.bat" "$(TargetPath)"

REM Run with 0, 1, 3 arguments

echo Run with 0 arguments
%MyProgram% >"%TEMP%\output.txt" && goto err 
echo Test 1 passed

echo Run with 1 arguments
%MyProgram% input.txt >"%TEMP%\output.txt" && goto err 
echo Test 2 passed

echo Run with 3 arguments
%MyProgram% input.txt output.txt "time" >"%TEMP%\output.txt" && goto err 
echo Test 3 passed

echo Faild to open fail
%MyProgram% test.txt "time" >"%TEMP%\output.txt" && goto err 
echo Test 4 passed

echo Find in empty file
%MyProgram% test1.txt "world" >"%TEMP%\output.txt" 
fc output1.txt "%TEMP%\output.txt" > nul || goto err
echo Test 5 passed

echo Find empty string
%MyProgram% input.txt "" >"%TEMP%\output.txt" 
fc output1.txt "%TEMP%\output.txt" > nul || goto err
echo Test 6 passed

echo Find in english text
%MyProgram% test2.txt "time" >"%TEMP%\output.txt" 
fc output2.txt "%TEMP%\output.txt" > null || goto err
echo Test 7 passed

echo Find in russian text
%MyProgram% test3.txt "звезды зажигают" >"%TEMP%\output.txt"
fc output3.txt "%TEMP%\output.txt" > null || goto err
echo Test 8 passed

echo English text not find 
%MyProgram% input.txt "meow" >"%TEMP%\output.txt" && goto err 
echo Test 9 passed

echo Russian text not find 
%MyProgram% test3.txt "м€у" >"%TEMP%\output.txt" && goto err 
echo Test 10 passed

REM “есты прошли упешно
echo All tests passed sucessfuly
exit /B 0

:err
echo Test faild
exit /B 1