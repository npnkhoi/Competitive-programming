var f:text;
    a,b:ansistring;
    i:longint;
begin
    assign(f,'samestr.inp'); reset(f);
    readln(f,a);
    readln(f,b);
    for i:= 1 to length(a) do if a[i]<>b[i] then writeln(i);
    readln;
end.