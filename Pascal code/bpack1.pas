uses crt,math;
var a:array[1..100] of integer;
    f:array[0..100,0..100] of integer;
    n,w,i,j:integer;
    g:text;
procedure input;
begin
    assign(g,'bpack.inp'); reset(g);
    readln(g,n,w);
    for i:= 1  to n do read(g,a[i]);
    close(g);
end;
procedure dp;
begin
    for i:= 0 to n do f[i,0]:= 0;
    for i:= 0 to w do f[0,i]:= 0;
    for i:= 1 to n do
    for j:= 1 to w do
        if a[i]<=j
            then f[i,j]:= max(f[i-1,j-a[i]]+a[i],f[i-1,j])
        else f[i,j]:=f[i-1,j];
end;
procedure trace;
begin
    i:= n; j:= w;
    repeat
        if f[i,j]<>f[i-1,j] then
            begin
                dec(j,a[i]);
                write(a[i],' ');
            end;
        dec(i);
    until f[i,j]=0;
    writeln('Max amount: ',f[n,w])
end;
begin
input;
dp;
trace;
readln;
end.