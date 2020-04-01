uses math;
const fin='bottles.inp';
	fon='';
	nmax=10007;
var fi,fo:text;
	a:array[0..nmax] of longint;
	f:array[1..2,0..nmax] of longint;
	n,i,row0,col0,count:longint;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n);
	for i:= 1 to n do read(fi,a[i]);
end;
procedure main;
begin
	f[1,0]:= 0; f[2,0]:= 0;
	f[1,1]:= a[1]; f[2,1]:= a[1];
	for i:= 2 to n do
	begin
		f[1,i]:=f[2,i-1]+a[i];
		f[2,i]:=max(f[1,i-2],f[2,i-2])+a[i];
	end;
end;
procedure backup(row,col:longint);
begin
	inc(count);
	if f[row,col]=a[col] then
        begin
                writeln(fo,count,' ',f[row0,col0]);
                writeln(fo,col,' ');
        end
		else
	begin
		if row=1 then backup(2,col-1)
			else if f[1,col-2]>f[2,col-2] then backup(1,col-2)
				else backup(2,col-2);
		writeln(fo,col,' ');
	end;
end;
procedure finish;
begin
	count:= 0;
	if max(f[1,n],f[2,n])>max(f[1,n-1],f[2,n-1]) then col0:= n else col0:= n-1;
	if max(f[1,n],f[1,n-1])>max(f[2,n-1],f[2,n]) then row0:= 1 else row0:= 2;
	backup(row0,col0);
	close(fi); close(fo);
end;
begin
        start;
        main;
        finish;
end.
