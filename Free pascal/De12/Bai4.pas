Program So_thap_phan;
uses crt;
var s:string;
procedure nhap(var s:string);
begin
  readln(s);
end;
function lt(n:byte):int64;
begin
  if (n=0) then
    exit(1)
  else
    begin
      lt:=1;
      while (n>0) do
        begin
          lt:=lt*2;
          dec(n);
        end;
    end;
end;
procedure xuly(s:string);
var t,tt,i,kq:integer;
begin
  t:=length(s)-1;
  kq:=0;
  for i:=1 to length(s) do
    begin
      val(s[i],tt);
      kq:=kq+(tt*lt(t));
      dec(t);
    end;
  write(kq);
end;
begin
  clrscr;
  nhap(s);
  xuly(s);
  readln
End.
