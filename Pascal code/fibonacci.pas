var f:array[0..1000] of int64;
    n,i:longint;
    m:int64;
    fi,fo:text;
procedure start;
begin
    assign(fi,'fibonacci.inp'); reset(fi);
    assign(fo,'fibonacci.out'); rewrite(fo);
    readln(fi,n,m);
end;
procedure build;
begin
    f[0]:= 0;
    f[1]:= 1;
    i:= 2;
    repeat f[i]:= f[i-1]+f[i-2]; inc(i);
    until f[i-1]>trunc(1e18);
end;
begin
    start;
    build;
    if m=0 then write(fo,0) else
    writeln(fo,m div f[n]);
    close(fi); close(fo);
end.



















































































