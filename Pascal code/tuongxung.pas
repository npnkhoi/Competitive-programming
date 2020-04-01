
uses math;
const fin='';
	fon='';
var fi,fo:text;
	n,m,i,j,x,y:longint;
        a,b:array[0..51,0..51] of char;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n,m);
	for i:= 1 to n do
        begin
	        for j:= 1 to n do read(fi,a[i,j]);
                readln(fi);
        end;
	for i:= 1 to m do
        begin
	        for j:= 1 to m do read(fi,b[i,j]);
                readln(fi);
        end;
end;
procedure finish;
begin
	close(fi); close(fo);
	halt;
end;
function same(x,y:longint):boolean;
var i,j:longint;
begin
	for i:= 1 to m do
	for j:= 1 to m do
	if a[x+i,y+j]<>b[i,j] then exit(false);
	exit(true);
end;
procedure main;
begin
	for x:= 0 to n-m do
	for y:= 0 to n-m do
		if same(x,y) then
		begin
			writeln(fo,'Yes');
			finish;
		end;
	writeln(fo,'No');
	finish;
end;

begin
        start;
        main;

end.
