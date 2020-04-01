
uses math;
const fin='lis.inp';
        fon='lis.out';
var fi,fo:text;
	a,f,h:array[0..30000] of longint;
	n,i,j,tmp,kq,l,r,mid:longint;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n);
	for i:=1 to n do read(fi,a[i]);
end;
procedure main;
begin
	a[0]:= 0;
	h[1]:= 1;
	kq:= 1;
	for i:= 2 to n do
	begin
		
		if a[i]<a[h[1]] then
		begin
			h[1]:= i;
			continue;
		end;
		if a[i]>a[h[kq]] then
		begin
			inc(kq);
            h[kq]:= i;
			continue;
		end;
		if (a[h[1]]<a[i]) and (a[i]<a[h[kq]]) then
		begin
			l:= 1;
			r:= kq;
			while l<r do
			begin
				mid:= (l+r+1) div 2;
				if a[h[mid]]>a[i] then r:= mid-1
					else l:= mid;
			end;
			if (a[h[l]]<a[i]) and (a[i]<a[h[l+1]]) then h[l+1]:= i;
		end;
	end;
end;
procedure finish;
begin
	writeln(fo,kq);
	close(fi); close(fo);
end;
begin
        start;
        main;
        finish;

end.
