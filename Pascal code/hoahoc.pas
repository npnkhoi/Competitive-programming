uses math;
type bang=record
	a:longint;
	b: longint;
	c:longint;
	end;
const fin='';
	fon='';
	maxc=5000;
var fi,fo:text;
	x:array[0..41] of bang;
	free:array[0..43] of boolean;
	n,ma,mb,sa,sb,sc,kq,i:longint;
	rate:real;

procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n,ma,mb);
	rate:= ma/mb;
	for i:= 1 to n do
	with x[i] do
	begin
		readln(fi,a,b,c);
		//r:= a/b;
	end;
end;
procedure try(i:longint);
var j: longint;
begin
	for j:= 1 to n do
	if (free[j]) and ((sa-rate*sb)*((x[j].a)-rate*(x[j].b))<0) and (sc+x[j].c<kq) then
	begin
		inc(sa,x[j].a); inc(sb,x[j].b); inc(sc,x[j].c);
		free[j]:= false;
		if (i=n) or (sa/sb=rate) then
			begin if sb/sb=rate then kq:= min(kq,sc) end
		else try(i+1);
		dec(sa,x[j].a); dec(sb,x[j].b); dec(sc,x[j].c);
		free[j]:= true;
	end;
end;
procedure main;
begin
	fillchar(free,sizeof(free),true);
	//qsort(1,n);
	kq:= maxc;
        sa:= 0;
        sb:= 0;
        try(1);
end;
procedure finish;
begin
        if kq=maxc then writeln(fo,-1)
        else writeln(fo,kq);
	close(fi); close(fo);
end;
begin
        start;
        main;
        finish;
end.





{// swap-------------------------------------
procedure swap(a,b:int64);
var tmp: int64;
begin
	tmp:= a; a:= b; b:= tmp;
end;
// quick sort -------------------------------
procedure qsort(l,r:int64);
begin
	mid:= x[(l+r) div 2];
	i:= l; j:= r;
	repeat
		while (x[i].r<mid) and (i<j) do inc(i);
		while (mid<x[j].r) and (i<j) do dec(j);
		if i<=j then
		begin
			swap(x[i],x[j]);
			inc(i); dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;}
