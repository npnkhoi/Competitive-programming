uses math;
const fmax=trunc(1e12)+1;
var c,a,b:array[0..1001,0..1001] of int64;
	q,m,n,i,j,loop:longint;
    f:text;
procedure start;
begin
	readln(f,m,n);
	for i:= 1 to m do
	for j:= 1 to n do read(f,c[i,j]);
	for i:= 1 to m do
	begin
		a[i,0]:= 0;
		b[i,0]:= fmax;
	end;
	for j:= 0 to n do
	begin
		b[0,j]:= 0;
		a[0,j]:= fmax;
	end;
end;
procedure main;
begin
	for i:= 1 to m do
	for j:= 1 to n do
	begin
		a[i,j]:= min(a[i-1,j],b[i-1,j]+c[i,j]);
		b[i,j]:= min(b[i,j-1],a[i,j-1]+c[i,j]);
	end;
end;
begin
	assign(f,''); reset(f);
	readln(f,q);
	for loop:= 1 to q do
	begin
		start;
		main;
		writeln(min(a[m,n],b[m,n]));
	end;
	close(f);
end.
