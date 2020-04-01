uses math,crt;
var a,b:ansistring;
    m,n,i,j,k:longint;
    f:array[0..2001,0..2001] of int64;
begin
    readln(a);
    readln(b);
    readln(k);
    m:= length(a); n:= length(b);
    for i:= 0 to m do f[i,0]:= k*i;
    for j:= 0 to n do f[0,j]:= k*j;
    for i:= 1 to m do
    for j:= 1 to n do
    f[i,j]:= min(f[i-1,j-1]+abs(ord(a[i])-ord(b[j])),min(f[i,j-1],f[i-1,j])+k);
    writeln(f[m,n]);
end.