uses math,crt;
var score:array[1..6] of byte = (15,19,5,3,1,10);
    cost:array[1..6] of byte = (2,3,2,1,1,1);
    f:array[0..1000001] of longint;
    i,j,t,n:longint;
procedure build;
begin
    f[0]:= 0;
    for i:= 1 to 1000000 do
    begin
        f[i]:= 1000001;
        for j:= 1 to 6 do if (score[j]<=i) then f[i]:= min(f[i],f[i-score[j]]+cost[j]);
    end;
end;
procedure main;
begin
    readln(t);
    for i:= 1 to t do
    begin
        readln(n);
        writeln(f[n]);
    end;
end;
begin
    build;
    main;
end.