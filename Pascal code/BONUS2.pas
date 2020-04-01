var fi,fo:text;
    m,n,q,i,j,x,y,u,v,loop:longint;
    a:array[0..1000,0..1000] of longint;
    s:array[0..1000,0..1000] of int64;
procedure start;
begin
    assign(fi,'BONUS.INP'); reset(fi);
    assign(fo,'BONUS.OUT'); rewrite(fo);
    readln(fi,m,n,q);
    for i:= 1 to m do
    for j:= 1 to n do read(fi,a[i,j]);
end;
procedure build;
begin
    for i:= 1 to n do s[0,i]:= 0;
    for j:= 1 to m do s[i,0]:= 0;
    for i:= 1 to m do
    for j:= 1 to n do
    s[i,j]:= s[i,j-1]+s[i-1,j]-s[i-1,j-1]+a[i,j];
    for i:= 1 to m do
    begin
    for j:= 1 to n do write(s[i,j]:5);
    writeln
    end;
end;
procedure main;
begin
    readln(fi,x,y,u,v);
    dec(x); dec(y);
    writeln(fo,s[u,v]+s[x,y]-s[x,v]-s[u,y]);
end;
begin
    start;
    build;
    for loop:= 1 to q do main;
    close(fi); close(fo);
end.