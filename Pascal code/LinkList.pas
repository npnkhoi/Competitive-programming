uses crt;
const maxN = 1000000 + 5;
var   n, q, x, y, i, ask: longint;
      a, left, right: array[1..maxN] of longint;
begin
        read(n);
        for i := 1 to n do read(a[i]);
        // init
        for i:= 1 to n do
        begin
                if (i = 1) then left[a[i]] := -1 else left[a[i]] := a[i-1];
                if (i = n) then right[a[i]] := -1 else right[a[i]] := a[i+1];
        end;
        read(q);
        for i:= 1 to q do
        begin
                read(ask);
                if (ask = 1) then
                begin
                        read(x, y);
                        // remove
                        if (right[x] <> -1) then left[right[x]] := left[x];
                        if (left[x] <> - 1) then right[left[x]] := right[x];
                        // insert
                        left[x] := left[y]; right[x] := y;
                        if (left[y] <> -1) then right[left[y]] := x;
                        left[y] := x;
                end
                        else
                begin
                        read(x);
                        writeln(left[x]);
                end;
        end;
end.