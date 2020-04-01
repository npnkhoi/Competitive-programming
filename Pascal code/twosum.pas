uses math;
const fin='twosum.inp';
	fon='';
var fi,fo:text;
	a,b:array[0..5007] of int64;
	n,i,tmp,j,dodai,dau:longint;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n);
	a[0]:= 0;
	for i:= 1 to n do
	begin
		read(fi,b[i]);
		a[i]:= a[i-1]+b[i];
	end;
end;
function check(l,r:longint):boolean;
var i,j,mid:longint;
	pre:int64;
begin
	i:= l; j:= r;
	pre:= a[l-1];
	while i<j do
	begin
		mid:=(i+j+1) div 2;
		if 2*(a[mid]-pre)<=a[r]-pre then i:= mid
		else j:= mid-1;
	end;
	if 2*(a[i]-pre)=(a[r]-pre) then exit(true) else exit(false);
end;
procedure finish;
begin
	writeln(fo,dodai);
	close(fi); close(fo);
        halt;
end;
procedure main;
begin
	for dodai:= n downto 0 do
		for dau:= 1 to n-dodai+1 do
		if check(dau,dau+dodai-1) then finish;
end;
begin
	start;
	main;
	finish;
end.
