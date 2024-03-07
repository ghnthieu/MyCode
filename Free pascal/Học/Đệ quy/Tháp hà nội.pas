Program Dequy;
uses crt;
var n:byte;
procedure nhap(var n:byte);
begin
  write('Nhap n: ');readln(n);
end;
procedure chuyen(n,x,y:byte);
begin
  if (n=1) then
    writeln('Chuyen 1 dia tu ',x,' sang ',y)
  else
    begin
      chuyen(n-1,x,6-x-y);
      chuyen(1,x,y);
      chuyen(n-1,6-x-y,y);
    end;
end;
Begin
  clrscr;
  nhap(n);
  chuyen(n,1,2);
  readln
End.