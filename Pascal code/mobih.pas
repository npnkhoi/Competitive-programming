uses math;
type int = longint; ll = int64;
var n, temp, rmax: ll;
    k: ll;
    a: array[0..20000001] of ll;
//////////////////////////////
procedure linput;
var i: int;
begin
    readln(n, k);
	rmax:= 0;
    for i := 1 to n do begin
        read(temp);
        readln(a[temp]);
        rmax := max( temp, rmax );
    end;
end;
/////////////////////////////
procedure solution;
var res, left: ll;
    right:int;
    i: int;
    sum: ll;
begin
    left := 0; right := 2*k;
    sum := 0;
    for i := 0 to 2*k do sum := sum + a[i];
    res := sum;

    for right:= 2*k+1 to 3000000 do
	begin
        inc(left);
        dec(sum, a[left-1]);
        inc(sum, a[right]);
        res := max(res,sum);
    end;
    write(res);
end;
////////////////////////////
begin
    linput;
    solution;
end.
