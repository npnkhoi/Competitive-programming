uses math;
const fin='game.inp';
	fon='game.out';
var fi,fo:text;
        wl:char;
	n,i,dau,cuoi,vt,mins,kq,tmp:longint;
        a,s:array[0..1000003] of longint;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n);
	for i:= 1 to n do
	begin
		readln(fi,wl,tmp);
                if wl='W' then a[i]:= tmp
		else a[i]:= -tmp;
	end;
	//---------------------
	s[0]:= 0;
	for i:= 1 to n do s[i]:=s[i-1]+a[i];
end;
procedure main;
begin
	mins:= 0; vt:= 0;
	kq:= s[1]; dau:= 1; cuoi:= 1;
	for i:= 2 to n do
	begin
		if s[i-1]<mins then
		begin
			mins:= s[i-1];
			vt:= i-1;
		end;
		if s[i]-mins>kq then
		begin
            kq:= s[i]-mins;
			dau:= vt+1;
			cuoi:= i;
		end;
        if (s[i]-mins=kq) and (vt+1<dau) then
        begin
            dau:= vt+1;
            cuoi:= i;
        end;
	end;
end;
procedure finish;
begin
	writeln(fo,kq);
	writeln(fo,dau,' ',cuoi);
	close(fi); close(fo);
end;
begin
	start;
	main;
    finish;
end.
