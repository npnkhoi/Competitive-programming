var a:array[1..100] of boolean;
    st:string;
    n,d,i,j,dem,max:byte;

function win(st:string):boolean;
var j: byte;
        ok: boolean;
begin
        ok:= false;
        for j:=1 to n do if st[j]='0' then
        begin
                ok:= true;
                break;
        end;
        exit(ok);
end;
begin
    fillchar(a,sizeof(a),false);
    readln(n,d);
    dem:= 0; max:= 0;
    for i:= 1 to d do
        begin
            readln(st);
            if win(st) then
                begin
                        inc(dem);
                        if dem>max then max:= dem;
                end
            else dem:= 0;
        end;
    write(max);
end.
