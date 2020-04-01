uses math;
const fin='path.inp';
    fon='path.out';
        nmax=1007;
        dmax=trunc(1e9);
type bang=record
	pre:longint;
	suf:longint;
	end;
var fi,fo:text;
	tt,deg,d:array[0..nmax] of longint;
	c,e:array[0..nmax,0..nmax] of longint;
        busy:array[0..nmax,0..nmax] of record
                ok:boolean;
                vao:longint;
                ra:longint;
                end;
	limit:array[0..nmax] of bang;
    free:array[0..nmax] of boolean;
	n,m,i,j,a,b,k,g,u,v,l,time,min,mark,x:longint;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n,m);
	readln(fi,a,b,k,g);
	for i:= 1 to g do read(fi,tt[i]);
	fillchar(deg,sizeof(deg),0);
	for i:= 1 to n do
	begin
		readln(fi,u,v,l);
		inc(deg[u]); e[u,deg[u]]:= v; c[u,deg[u]]:= l;
		inc(deg[v]); e[v,deg[v]]:= u; c[v,deg[v]]:= l;
	end;
        //deg[0]:= n;
        //for i:= 1 to n do e[0,i]:=i;
    for i:= 1 to n do
        begin
                limit[i].pre:= dmax;
                limit[i].suf:= -1;
        end;
    //time:= 0; tt[0]:= 0;
        for i:=1 to n do
        for j:=1 to n do
			begin
				busy[i,j].ok:= false;
				busy[i,j].vao:= dmax;
				busy[i,j].ra:= -1;
			end;
    time:= 0;
	for i:= 1 to g-1 do
	begin
                for mark:= 1 to n do if e[tt[i],mark]=tt[i+1] then break;
                v:=e[tt[i],mark];
                busy[tt[i],v].ok:= true;
                busy[tt[i],v].vao:= time;
                busy[v,tt[i]].vao:= time;
		        inc(time,c[tt[i],mark]);
                busy[v,tt[i]].ra:= time;
                busy[tt[i],v].ra:= time;
	end;
	 {for i:= 1 to n do
        begin
                limit[i].pre:= dmax;
                limit[i].suf:= -1;
        end;
    time:= 0; tt[0]:= 0;
	for i:= 0 to g-1 do
	begin
        for mark:= 1 to n do if e[tt[i],mark]=tt[i+1] then break;
        limit[tt[i+1]].pre:= time;
		inc(time,c[tt[i],mark]);
		limit[tt[i]].suf:= time;
	end;
	limit[tt[g]].suf:= dmax; limit[tt[1]].pre:= 0;}
end;
procedure main;
begin
	fillchar(free,sizeof(free),true);
    for i:= 1 to n do d[i]:= dmax;
	//fillchar(d,sizeof(d),dmax);
	d[a]:= k;
	repeat
		min:= dmax;
		for	i:= 1 to n do if (free[i]) and (d[i]<min) then
		begin
			u:= i; min:=d[i];
		end;
        free[u]:= false;
		if (u=b) or (min=dmax) then exit;
		for i:= 1 to deg[u] do
		begin
			v:= e[u,i];
			if (d[v]>d[u]+c[u,i]) then
            begin
                x:= d[u]+c[u,i];
					if (x<busy[u,v].vao) or (d[u]>busy[u,v].ra) then d[v]:= x
					else
					begin
					if d[v]>busy[u,v].ra+c[u,i] then d[v]:=busy[u,v].ra+c[u,i]
					end;

            end;
		end;
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
