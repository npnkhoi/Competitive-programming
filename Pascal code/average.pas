uses math;
const
    fin='average.inp';
    fon='average.out';
var fi,fo:text;
    a:array[0..300007] of int64;
        i,n,k,kmax,k0:longint;
        max,x: int64;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
        readln(fi,n,k);
        a[0]:= 0;
        for i:= 1 to n do
        begin
                read(fi,x);
                a[i]:=a[i-1]+x;
        end;
end;
procedure main;
begin
        max:= -1; kmax:= 1;
        for k0:=k to n do
        for i:= k0 to n do
                if (a[i]-a[i-k0])/k0>max/kmax then
                begin
                        max:=a[i]-a[i-k0];
                        kmax:=k0;
                end;
end;
procedure output;
begin
        writeln(fo,(max/kmax):0:6);
	close(fi); close(fo);
end;
begin
        input;
        main;
        output;

end.