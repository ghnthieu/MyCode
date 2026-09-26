Program Tong_n_So_lientiep_LT;
uses crt;
var n:byte;
procedure nhap(var n:byte);
begin
  readln(n);
end;
function lt(n,m:byte):int64;
begin
  lt:=1;
  while (m>0) do
    begin
      lt:=lt*n;
      dec(m);
    end;
end;
procedure xuly(n:byte);
var kq:int64;
    i:byte;
begin
  kq:=0;
  for i:=1 to n do
    if (i mod 2<>0) then
      kq:=kq+lt(i,i+1)
    else
      kq:=kq-lt(i,i+1);
  write(kq);
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.
