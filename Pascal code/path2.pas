uses math;
const fin='path.inp';
    fon='';
    nmax=1007;
    dmax=trunc(1e9)+7;
var fi,fo:text;
	tt,d:array[0..nmax] of longint;
	c,g:array[0..nmax,0..nmax] of longint;
    free:array[0..nmax] of boolean;
	n,m,i,j,a,b,k,g0,u,v,l,time,min0,mark,x:longint;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n,m);
	readln(fi,a,b,k,g0);
	for i:= 1 to g0 do read(fi,tt[i]);
	for i:= 1 to n do
	for j:= 1 to n do c[i,j]:=dmax;

	for i:= 1 to n do
	begin
		readln(fi,u,v,l);
		c[u,v]:= l; c[v,u]:= l;
	end;

	for i:=1 to n do
    for j:=1 to n do g[i,j]:= 0;
        g[tt[1],tt[2]]:= 0;
	for i:= 3 to g0 do
	begin
        g[tt[i-1],tt[i]]:=g[tt[i-2],tt[i-1]]+c[tt[i-2],tt[i-1]];
	end;
end;
procedure main;
begin
	fillchar(free,sizeof(free),true);
        for i:= 1 to n do d[i]:= dmax;
	d[a]:= k;
	repeat
		min0:= dmax;
                for     i:= 1 to n do if (free[i]) and (d[i]<min0) then begin u:= i; min0:=d[i]; end;
                free[u]:= false;
	        if (u=b) or (min0=dmax) then exit;
                for v:= 1 to n do if (d[v]>d[u]+c[u,v]) then d[v]:=min(d[v],max(d[u],g[v,u]+c[u,v])+c[u,v]);
	until false;
end;
procedure finish;
begin
	writeln(fo,d[b]-k);
	close(fi); close(fo);
end;
begin
	start;
	main;
	finish;
end.