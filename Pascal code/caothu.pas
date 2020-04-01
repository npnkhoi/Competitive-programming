uses math;
type edge=record
	u:longint; v:longint; c:longint; end;
var a:array[1..50000,1..50000] of longint;
	e:array[0..100000] of edge;
    pre:array[0..100000] of longint;
	n,m,i,j,k,ru,rv,kq:longint;
    fi,fo:text;
procedure start;
begin
	assign(fi,'caothu.inp'); reset(fi);
	assign(fo,'caothu.out'); rewrite(fo);
	readln(fi,n,m);
	for i:= 1 to n do
	for j:= 1 to n do a[i,j]:= 0;
	for i:= 1 to m do
	begin
		with e[i] do readln(fi,u,v,c);
		a[e[i].u,e[i].v]:= e[i].c;
		a[e[i].v,e[i].u]:= e[i].c;
	end;
end;
procedure sort(l,r:longint);
var i,j,mid:longint;
	tmp:edge;
begin
	i:= l; j:= r; mid:= e[(l+r) div 2].c;
	repeat
		while e[i].c<mid do inc(i);
		while e[j].c>mid do dec(j);
		if i<=j then
		begin
			tmp:= e[i]; e[i]:= e[j]; e[j]:= tmp;
			inc(i); dec(j);
		end;
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
end;
function root(u:longint):longint;
begin
	while pre[u]>0 do u:= pre[u];
	exit(u);
end;
procedure union(u,v:longint);
begin
	if pre[u]<pre[v] then
	begin
		inc(pre[u],pre[v]);
		pre[v]:= u;
	end
		else
	begin
		inc(pre[v],pre[u]);
		pre[u]:= v;
	end;
end;
procedure main;
begin
	for i:= 1 to n do pre[i]:= -1;
	for i:= m downto 1 do
	begin
		ru:= root(e[i].u); rv:= root(e[i].v);
		if ru=rv then
	begin
		kq:= 0;
		for k:= 1 to n do if (a[e[i].u,k]>0) and (a[e[i].v,k]>0)
		then kq:= max(kq,e[i].c+a[e[i].u,k]+a[e[i].v,k]);
		if kq>0 then exit;
	end
		else union(ru,rv);
    end;
end;
begin
	start;
    sort(1,m);
	main;
	writeln(fo,kq);
	close(fi); close(fo);
end.
