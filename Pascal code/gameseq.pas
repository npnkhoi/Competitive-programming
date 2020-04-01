type bang=record
	gt:int64;
	tt:int64;
	end;
const nmax=trunc(3e5)+7;
        fin='gameseq.inp';
        fon='gameseq.out';
var a:array[0..nmax] of bang;
	n,k,l,r,mid,value:int64;
        fi,fo:text;
    i: longint;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,n,k);
	for i:= 1 to n do
         read(fi,a[i].gt);
end;
procedure finish;
begin
	close(fi); close(fo); halt;
end;
procedure swap(var a,b:bang);
var t:bang;
begin
	t:= a; a:= b; b:= t;
end;
procedure qsort(l,r:longint);
var i,j,mid:longint;
begin
	i:= l; j:= r; mid:= a[(l+r) div 2].gt;
	repeat
                while a[i].gt<mid do inc(i);
                while a[j].gt>mid do dec(j);
		if i<=j then
		begin
			swap(a[i],a[j]);
			inc(i); dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure main;
begin
	for i:= 1 to n do a[i].tt:= i;
	qsort(1,n);
	for i:= 1 to n-1 do
	begin
		value:= a[i].gt+abs(k);
		l:= i+1; r:= n;
		while l<r do
		begin
			mid:= (l+r+1) div 2;
			if a[mid].gt>value then r:= mid-1
			else l:= mid;
		end;
		if a[l].gt-a[i].gt=k then
			begin
				writeln(fo,a[l].tt,' ',a[i].tt);
				finish;
			end
        else if a[i].gt-a[l].gt=k then
			begin
				writeln(fo,a[i].tt,' ',a[l].tt);
				finish;
			end;
	end;
	writeln(fo,-1); finish;
end;
begin
	start;
	main;
end.
