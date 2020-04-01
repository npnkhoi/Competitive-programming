uses math;
const
    fin='squid.inp';
	fon='squid.out';
	nmax=2*trunc(1e6)+7;
var g,x,a: array[0..nmax] of longint;
	fi,fo:text;
    n,k,i,xmax,xmin,dau,cuoi:longint;
	kq,s:int64;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n,k);
	fillchar(a,sizeof(a),0);
	for i:= 1 to n do
		begin
			readln(fi,g[i],x[i]);
			a[x[i]]:= g[i];
		end;
end;
procedure init;
begin
	// tim xmin, xmax---------------
	xmin:= x[1]; xmax:= x[1];
	for i:= 2 to n do
		begin
			if x[i]<xmin then xmin:=x[i];
			if x[i]>xmax then xmax:= x[i];
		end;
	// tinh s ban dau-----------------
	s:= 0; dau:= xmin; cuoi:= xmin+2*k;
	for i:= xmin to min(cuoi,xmax) do inc(s,a[i]);
	kq:= s;
end;
procedure main;
begin
	for cuoi:= xmin+2*k+1 to xmax do
	begin
		s:=s-a[dau]+a[cuoi];
		if s>kq then kq:= s;
		inc(dau);
	end;
end;
procedure output;
begin
	writeln(fo,kq);
	close(fi); close(fo);
end;
begin
	input;
	init;
	main;
	output;
end.