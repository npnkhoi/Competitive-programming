//uses crt;

var n,m,i,j:longint;
    c:array[0..51] of byte;
    f:array[0..251,0..51] of int64;
begin
    readln(n,m);
    for i:= 1 to m do read(c[i]);
    for i:= 1 to n do f[i,0]:= 0;
    for j:= 0 to m do f[0,j]:= 1;
    for i:= 1 to n do
    for j:= 1 to m do
    begin
        f[i,j]:= f[i,j-1];
        if c[j]<=i then f[i,j]:= f[i,j]+f[i-c[j],j];
    end;
    {for i:= 0 to n do
    begin
        for j:= 0 to m do write(f[i,j]:5);
        writeln;
    end;}
    writeln(f[n,m]);
end.