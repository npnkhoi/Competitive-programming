// std inout-----------------------------
uses math;
const fin='catgo.inp';
	fon='catgo.out';
	lmax=trunc(1e9)+7;
    nmax=trunc(1e5)+7;
var fi,fo:text;
    d:array[0..nmax] of longint;
    n,m,l,r,mid,i:longint;
    s:int64;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n,m);
	for i:= 1 to n do readln(fi,d[i]);
end;

function socot(x:longint):int64;
var i:longint;
begin
	s:= 0;
	for i:= 1 to n do inc(s,d[i] div x);
	exit(s);
end;

procedure main;
begin
	l:= 1; r:= lmax;
	while l<r do
	begin
		mid:=(l+r+1) div 2;
		if socot(mid)<m then r:= mid-1
			else l:= mid;
	end;
end;
procedure finish;
begin
	writeln(fo,l);
	close(fi); close(fo);
end;
begin
	start;
	main;
	finish;
end.
