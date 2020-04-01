// std inout-----------------------------
uses math;
const fin='';
	fon='';
var fi,fo:text;
procedure start;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
end;
procedure finish;
begin
	close(fi); close(fo);
end;
begin

end.
// swap-------------------------------------
procedure swap(a,b:int64);
var tmp: int64;
begin
	tmp:= a; a:= b; b:= tmp;
end;
// quick sort -------------------------------
procedure sort(l,r:int64);
begin
	mid:= (l+r) div 2;
	i:= l; j:= r;
	repeat
		while a[i]<mid do inc(i);
		while mid<a[j] do dec(j);
		if i<=j then 
		begin
			swap(a[i],a[j]);
			inc(i); dec(j);
		end;
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
end;
// bubble sort ------------------------
procedure bb_sort(n:int64);
begin
	for i:= 1 to n-1 do
	for j:= i+1 to n do
	if a[i]>a[j] then swap(a[i],a[j]);
end;