uses math;
const fmin=-2000;
type arr=array[0..1001] of integer;
var fi,fo:text;
    a,b:arr;
    n,p,k,l,r,s0,x,i,j,res:integer;
    f:array[0..1001,0..1001,0..1] of integer;
    s:array[0..1001,0..1] of integer;
procedure start;
begin
    assign(fi,'CF408_E.inp'); reset(fi);
    assign(fo,''); rewrite(fo);
    readln(fi,n,p,k);
end;
function sum(l,r,t:integer):integer;
begin
    exit(s[r,t]-s[l-1,t]);
end;
procedure build;
begin
    read(fi,r);
    for i:= 1 to r do
    begin
        read(fi,x);
        s[x,0]:= 1;
    end;
    read(fi,s0);
    for i:= 1 to s0 do
    begin
        read(fi,x);
        s[x,1]:= 1;
    end;
    for i:= 1 to n do
    for l:= 0 to 1 do
    s[i,l]:= s[i-1,l]+s[i,l];
end;
procedure main;
begin
    for j:= 1 to n do
    for l:= 0 to 1 do f[0,i,l]:= 0;
    for i:= 1 to p do
    for l:= 0 to 1 do f[i,0,l]:= 0;

    for i:= 1 to p do
    for j:= 1 to n do
    for l:= 0 to 1 do
    if j>k then
        f[i,j,l]:= max(f[i,j-1,l],f[i-1,j-k,l]+sum(j-k+1,j,l))
    else f[i,j,l]:= s[j,l];
end;
procedure finish;
begin
    res:= fmin;
    for i:= 0 to p do res:= max(res,f[i,n,0]+f[p-i,n,1]);
    for l:= 0 to 1 do
    begin
        for i:= 0 to p do
        begin
        for j:= 0 to n do write(f[i,j,l]:4);
        writeln;
        end;
        writeln;
    end;
    writeln(fo,res);
    close(fi); close(fo);
end;
begin
    start;
    build;
    main;
    finish;
end.
