uses math;
var a:array[1..100] of integer;
    f:array[0..10000,0..10000] of integer;
    n,w,i,j,s:integer;
    g,go:text;
procedure input;
begin
    assign(g,'chiakeo.inp'); reset(g);
    assign(go,'chiakeo.out'); rewrite(go);
    readln(g,n);
    s:= 0;
    for i:= 1  to n do
    begin
        read(g,a[i]);
        s:=s+a[i];
    end;
    w:= s div 2;
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
    {repeat
        if f[i,j]<>f[i-1,j] then
            begin
                dec(j,a[i]);
                write(a[i],' ');
            end;
        dec(i);
    until f[i,j]=0;}
    writeln(go,abs(s-2*f[n,w]));
    close(go);
end;
begin
input;
dp;
trace;
end.
