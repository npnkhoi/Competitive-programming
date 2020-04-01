uses math;
type bang=record
    a:longint;
    b:longint;
    c:longint;
    end;
const
	fin='dq.inp';
	fon='';
        maxx=10000;
var f:array[0..10007] of longint;
    d:array[0..10003] of bang;
	n,i,j,max1,max2:longint;
	fi,fo:text;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n);
	for i:= 1 to n do
    with d[i] do readln(fi,a,b,c);
end;

procedure sort(l,r:longint);
var i,j,mid:longint;
    tmp: bang;
begin
    i:= l; j:= r;
    mid:= d[(l+r) div 2].b;
    while d[i].b<mid do inc(i);
    while d[j].b>mid do dec(j);
    if i<=j then
    begin
        tmp:= d[i]; d[i]:=d[j]; d[j]:= tmp;
        inc(i); dec(j);
    end;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;
procedure main;
begin
    max2:= 0;
    for i:= 0 to n do f[i]:= 0;

    for i:= 1 to n do
    begin
        max1:= 0;
        j:= 1;
        while (d[j].b<=d[i].a) and (j<=n) do
        begin
            max1:= max(max1,f[j]);
            inc(j);
        end;
        f[i]:= max(max1+d[i].c,max2);
        max2:= max(max2,f[i]);
    end;
end;
procedure finish;
begin
    writeln(fo,max2);
    close(fi); close(fo);
end;
begin
        start;
        sort(1,n);
        main;
        finish;
end.
