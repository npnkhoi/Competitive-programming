var a:array[1..1000,1..1000] of 0..1;
	n,i,j,k:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,'nktrio.inp'); reset(fi);
	assign(fo,'nktrio.out'); rewrite(fo);
	readln(fi,n);
	for i:= 1 to n do
    begin
	for j:= 1 to n do read(fi,a[i,j]);
    readln(fi);
    end;
end;
procedure main;
begin
	for i:= 1 to n-2 do
	for j:= i+1 to n-1 do
	for k:= j+1 to n do
	if ((a[i,j]=1)and(a[j,k]=1)and(a[k,i]=1)) or ((a[j,i]=1)and(a[k,j]=1)and(a[i,k]=1)) then
	begin
		writeln(fo,i,' ',j,' ',k); exit;
	end;
	writeln(fo,-1)
end;
begin
	start;
	main;
	close(fi); close(fo);
end.