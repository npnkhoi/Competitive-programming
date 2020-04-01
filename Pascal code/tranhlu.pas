uses math;
const fin='tranhlu.inp';
	fon='tranhlu.out';
var fi,fo:text;
	a:array[0..53,0..53] of char;
	tmp:array[0..2503] of record
                x:longint;
                y:longint;
                end;
	m,n,i,j,dem,time:longint;
        stop:boolean;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,m,n);
	for i:= 1 to m do
        begin
	        for j:=1 to n do read(fi,a[i,j]);
                readln(fi);
        end;
end;
procedure xuatbang;
begin
        for i:= 1 to m do
        begin
        for j:= 1 to n do write(fo,a[i,j]);
        writeln;
        end;
        readln;
end;
procedure finish;
begin
	close(fi); close(fo);
end;
procedure nguoidi;
begin
	dem:= 0;
	for i:= 1 to m do
	for j:= 1 to n do if a[i,j]='.' then
	if (a[i-1,j]='S') or (a[i+1,j]='S') or (a[i,j-1]='S') or (a[i,j+1]='S') then
	begin
		inc(dem);
		tmp[dem].x:= i;
		tmp[dem].y:= j;
	end;
	if dem=0 then stop:= true;
	for i:= 1 to dem do a[tmp[i].x,tmp[i].y]:= 'S';
end;
procedure ktra_antoan;
begin
	for i:= 1 to m do
	for j:= 1 to n do if a[i,j]='D' then
	if (a[i-1,j]='S') or (a[i+1,j]='S') or (a[i,j-1]='S') or (a[i,j+1]='S') then
	begin
		writeln(fo,time);
		finish;
		halt;
	end;
end;
procedure lucuon;
begin
	dem:= 0;
	for i:= 1 to m do
	for j:= 1 to n do if (a[i,j]='.') or (a[i,j]='S') then
	if (a[i-1,j]='*') or (a[i+1,j]='*') or (a[i,j-1]='*') or (a[i,j+1]='*') then
	begin
		inc(dem);
		tmp[dem].x:= i;
		tmp[dem].y:= j;
	end;
	for i:= 1 to dem do a[tmp[i].x,tmp[i].y]:= '*';
end;
procedure main;
begin
	time:= 0;
	repeat
		inc(time);
                ktra_antoan;
                //writeln(fo,time);
		stop:= false;
		nguoidi;
                //xuatbang;
		lucuon;
                //xuatbang;
	until stop;
end;
begin
        start;
	main;
	writeln(fo,'CHETCHIM');
	finish;
end.
