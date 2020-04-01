uses math;
const fin='';
	fon='';
var fi,fo:text;
	c:array[0..10,0..10] of byte;
	free:array[0..10] of boolean;
	a:array[0..10] of longint;
	n,m,i,u,v:longint;
	count:int64;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n,m);
	fillchar(c,sizeof(c),0);
	fillchar(free,sizeof(free),true);
	for i:= 1 to m do
	begin
		readln(fi,u,v);
		c[u,v]:= 1;
		c[v,u]:= 1;
	end;
end;
procedure try(i:longint);
var u,v:longint;
begin
	u:= a[i-1];
	for v:= 1 to n do if (free[v]) and (c[u,v]=1) then
	begin
		a[i]:= v;
		free[v]:= false;
		if i=n then inc(count) else try(i+1);
		free[v]:= true;
	end;
end;
procedure main;
begin
	a[1]:= 1;
	free[1]:= false;
	count:= 0;
	try(2);
end;
procedure finish;
begin
	writeln(fo,count);
	close(fi); close(fo);
end;
begin
	start;
	main;
	finish;
end.
