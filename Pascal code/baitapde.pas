uses crt;
var a,b: longint;

function ucln(a,b: longint):longint;
begin
        if (a<>0) and (b<>0) then
        begin
        while a <>b do
        if a >b then a:=a-b
        else b:=b-a;
        exit(b);
        end
        else exit(a+b);
end;







begin
        readln(a,b);
        writeln(ucln(a,b));

end.
