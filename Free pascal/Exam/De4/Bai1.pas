Program bai1;
uses crt;
var n:qword;
procedure nhap(var n:qword);
begin
  repeat
    readln(n);
  until (n>=0) and (n<=10000000000000000000);
end;
procedure xuly(n:qword);
var dem,i,max:byte;
    tong:integer;
begin
  dem:=0;
  tong:=0;
  max:=0;
  while n<>0 do
    begin
      inc(dem);
      i:=n mod 10;
      n:=n div 10;
      if i>max then
        max:=i;
      tong:=tong+i;
    end;
  writeln('So nguyen N co ',dem,' chu so');
  writeln('Tong cac chu so cua N la: ',tong);
  writeln('Chu so lon nhat: ',max);
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.
