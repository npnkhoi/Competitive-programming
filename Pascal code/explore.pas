uses math;
const fin='explore.inp';
	fon='';
        nmax=trunc(5e4)+7;
var fi,fo:text;
        a:array[0..nmax] of longint;
        n,t,i,mark,kq,limit,s:longint;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
        readln(fi,t,n);
        for i:=1 to n do read(fi,a[i]);
end;
procedure swap(a,b:int64);
var tmp: int64;
begin
	tmp:= a; a:= b; b:= tmp;
end;
// quick sort -------------------------------
procedure qsort(l,r:longint);
var mid,i,j: longint;
begin
	mid:= a[(l+r) div 2];
	i:= l; j:= r;
	repeat
                while a[i]<a[mid] do inc(i);
                while a[mid]<a[j] do dec(j);
		if i<=j then
		begin
			swap(a[i],a[j]);
			inc(i); dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
function maxphai(x:longint):longint;
var t0:longint;
begin
        t0:=t+a[x];
        i:= x;
        while (i<=n) and (a[i+1]-a[x]<=t0) do inc(i);
        exit(i);
end;
function maxtrai(x:longint):longint;
var t0:longint;
begin
        t0:= t-a[x];
        i:= x;
        while (i>=1) and (a[x]-a[i-1]>=t0) do dec(i);
        exit(i);
end;
procedure main;
begin
        qsort(1,n);
        limit:= 0;
        for i:= 1 to n do if a[i]<0 then limit:= i else exit;
        mark:= 1; kq:= 0;
        for mark:= 1 to mark do if abs(a[mark])<=t then
        begin
                if a[mark]<0 then s:= max(maxphai(mark),limit)-mark+1
                else s:=mark-min(maxtrai(mark),limit+1)+1;
                if s>kq then kq:= s;
        end;
end;
procedure output;
begin
        writeln(fo,kq);
	close(fi); close(fo);
end;
begin
        input;
        main;
        output;

end.
