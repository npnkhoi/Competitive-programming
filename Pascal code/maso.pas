uses math;
const fin='';
	fon='';
var fi,fo:text;
    a:array[0..80000] of boolean;
    n,k,i,count,p:longint;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
    readln(fi,n,k);
    fillchar(a,sizeof(a),true);
    for i:= 1 to n do
    begin
        readln(fi,p);
        a[p]:= false;
    end;
end;
procedure output;
begin
    i:= 0; count:= 0;
    repeat
        inc(i);
        if a[i] then begin inc(count); writeln(fo,i); end;
    until count=k;
	close(fi); close(fo);
end;
begin
    input;
    output;

end.