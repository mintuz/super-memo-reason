let newFactor = (~quality, ~ef) => {
  ef
  +. (
    0.1
    -. (5.0 -. float_of_int(quality))
    *. (0.08 +. (5.0 -. float_of_int(quality)) *. 0.02)
  );
};

type response = {
  .
  nextDate: float,
  easinessFactor: float,
};

let calculate = (~quality, ~repetitionsCount, ~ef) => {
  let newRepetitionCount = quality < 3 ? 0 : repetitionsCount + 1;
  let newEasinessFactor = ref(newFactor(~quality, ~ef));
  newEasinessFactor := newEasinessFactor^ > 1.3 ? newEasinessFactor^ : 1.3;

  let newInterval =
    switch (newRepetitionCount) {
    | newRepetitionCount when newRepetitionCount <= 1 => 1
    | newRepetitionCount when newRepetitionCount == 2 => 6
    | newRepetitionCount => newRepetitionCount
    };

  let secondsInDay = 60 * 60 * 24;
  let now = Js.Date.make();
  let nextDate =
    Js.Date.valueOf(now)
    +. float_of_int(newInterval)
    *. float_of_int(secondsInDay);
  let response: response = {
    val _nextDate = nextDate;
    val _easinessFactor = newEasinessFactor^;
    pub nextDate = _nextDate;
    pub easinessFactor = _easinessFactor
  };

  response;
};
