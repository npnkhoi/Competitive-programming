uses crt;
var f:array[1..1000] of int64;
    i:longint;
begin
    f[1]:= 0; f[2]:= 1;
    for i:= 3 to 80 do
    begin
        f[i]:= f[i-1]+f[i-2]; writeln(f[i]);
    end;
end.