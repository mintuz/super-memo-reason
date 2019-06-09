open Jest;
open SuperMemo;

describe("SuperMemo Algoritmn", () =>
  Expect.(
    describe("Easiness Factor", () => {
      test("Let easiness factor equal 1.3 when less than 1.3", () => {
        let quality = 3;
        let easinessFactor = 1.2;
        let repetitionsCount = 1;
        let response =
          SuperMemo.calculate(
            ~quality,
            ~repetitionsCount,
            ~ef=easinessFactor,
          );
        expect(response#easinessFactor) |> toEqual(1.3);
      });

      test("When quality increases, increase the easiness factor", () => {
        let quality = 5;
        let easinessFactor = 1.5;
        let repetitionsCount = 1;
        let response =
          SuperMemo.calculate(
            ~quality,
            ~repetitionsCount,
            ~ef=easinessFactor,
          );
        expect(response#easinessFactor) |> toEqual(1.6);
      });

      test("When quality decreases, decrease the easiness factor", () => {
        let quality = 1;
        let easinessFactor = 2.5;
        let repetitionsCount = 1;
        let response =
          SuperMemo.calculate(
            ~quality,
            ~repetitionsCount,
            ~ef=easinessFactor,
          );
        expect(response#easinessFactor) |> toEqual(1.96);
      });
    })
  )
);
