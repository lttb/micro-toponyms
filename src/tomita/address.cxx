#encoding "utf8"

StreetW ->
  'проспект'
  | 'проезд'
  | 'улица'
  | 'шоссе'
  | 'набережная'
  | 'площадь'
  | 'переулок'
  | 'квартал'
  | 'тупик'
  | 'линия'
  | 'аллея'
  | 'бульвар'
  | 'просека'
  | 'район'
  | 'мост';

StreetSokr ->
  'пр-т' | 'пр' | 'пр.' | 'просп' | 'просп.'
  | 'пр-д'
  | 'ул' | 'ул.'
  | 'ш' | 'ш.'
  | 'наб' | 'наб.'
  | 'пл' | 'пл.'
  | 'б-р'
  | 'пер' | 'пер.'
  | 'р-н';

StreetDescr -> StreetW | StreetSokr;

StreetNameNoun -> (Adj<gnc-agr[1]>) Word<gnc-agr[1],rt> (Word<gram="род">);

NumberW_1 -> AnyWord<wff=/[1-9]?[0-9]-?((ый)|(ий)|(ой)|й)/> {outgram="муж, ед, им"};
NumberW_2 -> AnyWord<wff=/[1-9]?[0-9]-?((ая)|(яя)|(ья)|я)/> {outgram="жен, ед, им"};
NumberW_3 -> AnyWord<wff=/[1-9]?[0-9]-?((ее)|(ье)|(ое)|е)/> {outgram="сред, ед, им"};

NumberW -> NumberW_1 | NumberW_2 | NumberW_3;

StreetNameAdj -> Adj<h-reg1> Adj*;
StreetNameAdj -> NumberW<gnc-agr[1]> Adj<gnc-agr[1]>;


Street -> StreetDescr interp (Street.Descr) StreetNameNoun<gram="род", h-reg1> interp (Street.StreetName::not_norm);
Street -> StreetDescr interp (Street.Descr) StreetNameNoun<gram="им", h-reg1> interp (Street.StreetName::not_norm);

Street -> StreetNameAdj<gnc-agr[1]> interp (Street.StreetName) StreetW<gnc-agr[1]> interp (Street.Descr);
Street -> StreetNameAdj interp (Street.StreetName) StreetSokr interp (Street.Descr);

Street -> StreetW<gnc-agr[1]> interp (Street.Descr) StreetNameAdj<gnc-agr[1]> interp (Street.StreetName);

Street -> StreetSokr interp (Street.Descr) StreetNameAdj interp (Street.StreetName);

StreetName -> Word<kwtype=streetname, h-reg1, gram="дат">;
StreetName -> Word<kwtype=streetname, h-reg1, gram="geo">;
Street -> StreetName interp (Street.StreetName::norm="ед, им");
