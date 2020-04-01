uses crt;
var x:array[1..100] of integer;
    sum,n,dem:integer;
Procedure PrintResult;
var i:integer;
begin
inc(dem);
for i:=1 to n*2 do if x[i]=1 then write('(') else write(')');
write('  ',dem);
writeln;
end;
Procedure Try(i:integer);
var j:integer;
begin
        if sum<0 then exit;
        for j:=0 to 1 do
                begin
                        x[i]:=j;
                        if (i=n*2) then if sum=1 then begin PrintResult;exit;end else exit
                        else
                        begin
                        if j=0 then dec(sum) else inc(sum);
                        Try(i+1);
                        if j=0 then inc(sum) else dec(sum);
                        end;
                end;
end;
begin
read(n); sum:=0;
Try(1);
readkey;
end.