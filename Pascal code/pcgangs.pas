			a[p,q]:= 1; a[q,p]:= 1;
			e[m_e].u:= p;
			e[m_e].v:= q;
			else
			else
			inc(m_e);
			pre[ru]:= pre[ru]+pre[rv];
			pre[ru]:= rv;
			pre[rv]:= pre[rv]+pre[ru];
			pre[rv]:= ru;
		begin
		begin
		begin
		else if a[e[i].v,k]=1 then union(k,e[i].u);
		end
		end;
		end;
		if a[e[i].u,k]=1 then union(k,e[i].v)
		if count=n-1 then exit;
		if kitu='F' then union(p,q)
		if pre[ru]<pre[rv] then
		inc(count);
		readln(fi,kitu,p,q);
	//----------------------------------
	begin
	begin
	begin
	e:array[0..5003] of edge;
	end;
	end;
	end;
	exit(u);
	for i:= 1 to m do
	for i:= 1 to m_e-2 do
	for i:= 1 to n do if pre[i]<0 then inc(kq);
	for i:= 1 to n do pre[i]:= -1;
	for k:= 1 to n do	
	if count=n-1 then exit;
	if ru<>rv then
	kitu:char;
	m_e:= 0; count:= 0;
	pre:array[0..1003] of longint;
	ru:= root(u); rv:= root(v);
	u:longint; v:longint; end;
	while pre[u]>0 do u:= pre[u];
	writeln(fo,kq);
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    close(fi); close(fo);
    fi,fo:text;
    finish;
    kq:= 0;
    n,m,m_e,i,j,k,kq,count,s,p,q:longint;
    readln(fi,m);
    readln(fi,n);
    start;
begin
begin
begin
begin
begin
const fin=''; fon='';
end.
end;
end;
end;
end;
function root(u:longint):longint;
procedure finish;
procedure start;
procedure union(u,v:longint);
type edge=record
var a:array[0..1003,0..1003] of 0..1;
var ru,rv:longint;