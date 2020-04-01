uses math;
const fmin=-2000;
type arr=array[0..1001] of integer;
var fi,fo:text;
    a,b:arr;
    n,p,k,l,r,s,x,i,j,res:integer;
    f:array[0..1001,0..1001,0..1] of integer;
procedure start;
begin
    assign(fi,'CF408_E.inp'); reset(fi);
    assign(fo,''); rewrite(fo);
    readln(fi,n,p,k);
end;
function sum(a:arr;l,r:longint):longint;
begin
    exit(a[r]-a[l-1]);
end;
procedure build;
begin
    read(fi,r);
    for i:= 1 to r do
    begin
        read(fi,x);
        a[x]:= 1;
    end;
    read(fi,s);
    for i:= 1 to s do
    begin
        read(fi,x);
        b[x]:= 1;
    end;
    for i:= 1 to n do
    begin
        a[i]:= a[i-1]+a[i];
        b[i]:= b[i-1]+b[i];
    end;
end;
procedure main;
begin
    for i:= 1 to n do
    for j:= 1 to p do
    for l:= 0 to 1 do f[i,j,l]:= fmin;

    for i:= 1 to min(n,k) do
    begin
        f[i,1,0]:= sum(a,1,i);
        f[i,1,1]:= sum(b,1,i);
    end;

    for j:= 2 to p do
    for i:= j to min(n,j*k) do
    begin
        for l:= j-1 to i-2 do
        begin
            f[i,j,0]:= max(f[i,j,0],  max(f[l,j-1,1],f[l,j-1,0])+sum(a,l+1,i));
            f[i,j,1]:= max(f[i,j,1],  max(f[l,j-1,0],f[l,j-1,1])+sum(b,l+1,i));
        end;
        f[i,j,0]:= max(f[i,j,0],f[i-1,j-1,1]+sum(a,i,i));
        f[i,j,1]:= max(f[i,j,1],f[i-1,j-1,0]+sum(b,i,i));
    end;
end;
procedure finish;
begin
    res:= fmin;
    for i:= 1 to n do
    for j:= 1 to p do
    for l:= 0 to 1 do
    res:= max(res,f[i,j,l]);
    writeln(fo,res);
    for l:= 0 to 1 do
    begin
        for i:= 1 to n do
        begin
        for j:= 1 to p do write(f[i,j,l]:5);
        writeln;
        end;
        writeln;
    end;
    for i:= 0 to n do write(a[i]:5);
    writeln;
    for i:= 0 to n do write(b[i]:5);
    close(fi); close(fo);
end;
begin
    start;
    build;
    main;
    finish;
end.