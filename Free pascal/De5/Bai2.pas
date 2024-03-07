Program bai2;
uses crt;
var s:string;
    i:byte;
procedure nhap(var s:string);
begin
  write('Nhap xau S: ');readln(s);
end;
function nhip(ch:char):string;
var st,a:string;
    t:byte;
begin
  st:='';
  t:=ord(ch);
  while t<>0 do
    begin
      str(t mod 2,a);
      st:=a+st;
      t:=t div 2;
    end;
  while length(st)<=7 do
    st:='0'+st;
  nhip:=st;
end;
procedure xuly(s:string);
var i:byte;
    kq:string;
begin
  kq:='';
  for i:=1 to length(s) do
    kq:=kq+nhip(s[i]);
  write(kq);
end;
Begin
  clrscr;
  nhap(s);
  xuly(s);
  readln
End.
