
uses math,crt;
const fin='move.inp';
    fon='';
var a,f:array[0..503,0..503] of longint;
    m,n,i,j:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,m,n);
    for i:= 1 to m do
    begin
        for j:= 1 to n do read(fi,a[i,j]);
        readln(fi);
    end;
end;
procedure xuat;
var i,j:longint;
begin
    for i:= 1 to m do
    begin
        for j:= 1 to n do write(f[i,j],' ');
        writeln;
    end;
    readln;
end;
procedure main;
begin
    f[1,1]:= a[1,1];
    for j:= 2 to n do f[1,j]:= f[1,j-1]+a[1,j];
    for i:= 2 to m do f[i,1]:= f[i-1,1]+a[i,1];
    for i:= 2 to m do
    for j:= 2 to n do
    begin
    f[i,j]:= a[i,j]+max(f[i-1,j],f[i,j-1]);
    //xuat;
    end;
end;
begin
    start;
    main;
    writeln(fo,f[m,n]);
    close(fi); close(fo);
end.
