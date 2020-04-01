uses math;
const fin='tamphan.inp';
	fon='tamphan.out';
    tmax=2*trunc(1e9)+3;
var fi,fo:text;
	x,y:array[0..50] of double;
	t,d:array[0..50,0..50] of double;
	i,j,k,n,kc:integer;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n);
	for i:= 1 to n do readln(fi,x[i],y[i]);
	for i:= 1 to n do
	for j:= 1 to n do
    if abs(i-j)<>1 then
	d[i,j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
end;
procedure main;
begin
	for i:=1 to n do
	for j:= 1 to n do
	if j-i<3 then t[i,j]:= 0;

	for kc:=3 to n-1 do
	for i:= 1 to n-kc do
	begin
		j:=i+kc;
		t[i,j]:= tmax;
		for k:= i+1 to j-1 do
		t[i,j]:=min(t[i,j],t[i,k]+t[k,j]+d[i,k]+d[k,j]);
	end;
end;
procedure finish;
begin
	writeln(fo,t[1,n]:0:4);
	close(fi); close(fo);
end;
begin
	start;
	main;
	finish;
end.
