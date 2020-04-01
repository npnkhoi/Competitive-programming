uses math;
const fin='checkin.inp';
	fon='checkin.out';
        nmax=trunc(1e6)+7 ;
var fi,fo:text;
        a:array[1..nmax] of longint;
        n,m,i:longint;
        s,max,l,r,mid:int64;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
        readln(fi,n,m);
        max:= 0;
        for i:= 1 to n do
                begin
                        readln(fi,a[i]);
                        if a[i]>max then max:= a[i];
                end;
        max:=max*m;
end;
function songuoi(t:int64):int64;
begin
        s:= 0;
        for i:= 1 to n do s:=s+t div a[i];
        exit(s);
end;
function min(l,r:longint):longint;
var mid:longint;
begin
        if r-l<=1 then if songuoi(l)>=m then exit(l)
        else exit(r);
        mid:= (l+r+1) div 2;
        if songuoi(mid)<m then exit(min(mid,r))
        else exit(min(l,mid));
end;
procedure main;
begin
        l:= 1; r:= max;
        while r-l>1 do
        begin
                mid:= (l+r+1) div 2;
                if songuoi(mid)<m then l:= mid
                else r:= mid;
        end;
end;
procedure output;
begin
        if songuoi(l)>=m then writeln(fo,l)
        else writeln(fo,r);
	close(fi); close(fo);
end;
begin
        input;
        main;
        output;
end.