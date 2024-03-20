chcp 1251
 
SET MyProgram="%~1"
 
if %MyProgram% == "" (
	echo Please specify path to program
	exit /B 1
)

REM "$(ProjectDir)Tests.bat" "$(TargetPath)"

echo Run with 0 arguments
%MyProgram% >"%TEMP%\output.txt" && goto err 
echo Test 1 passed

echo Run with 2 arguments
%MyProgram% input.txt input1.txt>"%TEMP%\output.txt" && goto err 
echo Test 2 passed

echo Faild to open fail
%MyProgram% test.txt >"%TEMP%\output.txt" && goto err 
echo Test 3 passed

echo Empty file
%MyProgram% empty.txt >"%TEMP%\output.txt" && goto err 
echo Test 4 passed

echo Determinate = 0
%MyProgram% determinate0.txt >"%TEMP%\output.txt" && goto err 
echo Test 5 passed

echo Invert matrix
%MyProgram% input.txt >"%TEMP%\output.txt"
fc output.txt "%TEMP%\output.txt" || goto err
echo Test 6 passed


echo All tests passed sucessfuly
exit /B 0

:err
echo Test faild
exit /B 1