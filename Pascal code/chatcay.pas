uses math;
const fin='chatcay.inp';
        fon='chatcay.out';
var c,v:array[0..10007] of longint;
    f:array[0..1007,0..1007] of longint;
    n,w,i,j:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n,w);
    for i:= 1  to n do read(fi,v[i],c[i]);
end;
procedure dp;
begin
    for i:= 0 to n do f[i,0]:= 0;
    for i:= 0 to w do f[0,i]:= 0;
    for i:= 1 to n do
    for j:= 1 to w do
        if v[i]<=j
            then f[i,j]:= max(f[i-1,j-v[i]]+c[i],f[i-1,j])
        else f[i,j]:=f[i-1,j];
end;
{procedure trace;
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
end;              }
procedure finish;
begin
	writeln(fo,f[n,w]);
	close(fi); close(fo);
end;
begin
start;
dp;
finish;
end.
