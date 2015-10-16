#ifndef UNIT
#define UNIT

#include <QString>
#include <QMetaType>
#include <QVariant>

class Unit
{
public:
  Unit() {}
  ~Unit() {}

  enum LengthUnit {
    kMeter,
    kKiloMeter,
    kFeet,
    kMile,
    kMaxLengthUnit
  };

  enum ImpedanceUnit {
    kOhm,
    kOhmPerMeter,
    kOhmPerKilometer,
    kOhmPerFeet,
    kOhmPerMile,
    kMaxImpedanceUnit
  };

  enum PowerUnit {
    kVA,
    kKiloVA,
    kMegaVa,
    kMaxPowerUnit
  };

  enum VoltageUnit {
    kVolts,
    kKiloVolts,
    kMaxVoltageUnit
  };

  enum CurrentUnit {
    kAmpere,
    kKiloAmpere,
    kMaxCurrentUnit
  };

  static QString lengthUnitToStr(LengthUnit lengthUnit);
  static QString impedanceUnitToStr(ImpedanceUnit impedanceUnit);
  static QString powerUnitToStr(PowerUnit powerUnit);
  static QString voltageUnitToStr(VoltageUnit voltageUnit);
  static QString currentUnitToStr(CurrentUnit currentUnit);
};

Q_DECLARE_METATYPE(Unit::LengthUnit)
Q_DECLARE_METATYPE(Unit::ImpedanceUnit)
Q_DECLARE_METATYPE(Unit::PowerUnit)
Q_DECLARE_METATYPE(Unit::VoltageUnit)
Q_DECLARE_METATYPE(Unit::CurrentUnit)
#endif // UNIT

