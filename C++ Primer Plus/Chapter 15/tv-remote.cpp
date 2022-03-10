#include <iostream>

namespace {
    class Tv; // forward declaration

    class Remote {
    private:
        enum class InputMode: bool {Normal, Interactive};
        Tv *paired_tv_;
        InputMode mode_;

    public:
        friend class Tv;    // give all methods of tv unrestricted access

        explicit Remote(Tv *paired_tv) { paired_tv_ = paired_tv; }
        void changeTv(Tv *new_tv)      { paired_tv_ = new_tv;    }
        void volup()   const;
        void voldown() const;
        void toggleOnOff() const;
        void channelUp()   const;
        void channelDown() const;
        void setChannel(int chan) const;
        void setBroadCastType()   const;
        void setInput() const;
        void showMode() const {
            std::cout << "Input Mode: " << (mode_ == InputMode::Normal ? "Normal" : "Interactive")
                      << '\n';
        }
    };

    class Tv {
    public:
        friend void Remote::setChannel(int chan) const; // only one remote method gets
                                                        // private access
        enum class Mode : short {OFF, ON};
        enum class Input: short {TV, DVD};
        enum class BroadCastType: short {Antenna, Cable};
        enum {MinVal=1, MaxVal=50};

        class TvOffException: public std::logic_error {
        public:
            explicit TvOffException(const std::string & msg="")
                : std::logic_error(msg) { }
            virtual ~TvOffException() noexcept { }
        };
    private:
        Mode mode_;
        Input input_;
        BroadCastType broadcast_;
        int maxChannel_ = MaxVal;
        int channel_    = MinVal;
        int volume_     = 5;

    public:
        Tv(Mode mode=Mode::OFF, Input inp=Input::TV, 
           BroadCastType bt=BroadCastType::Antenna) {
            mode_ = mode;
            input_ = inp;
            broadcast_ = bt;
        }
        void volup()   { volume_++; }
        void voldown() { volume_ = (volume_ - 1 <= 0) ? 0 : volume_ - 1; }
        void toggleOnOff() { mode_ = (mode_ == Mode::OFF) ? Mode::ON : Mode::OFF; }
        void channelUp()   { channel_ = (channel_ + 1) % maxChannel_; }
        void channelDown() { channel_ = (channel_ - 1 <= 0) ? MaxVal : channel_ - 1; }
        void setBroadCastType() {
            broadcast_ = (broadcast_ == BroadCastType::Antenna) 
                         ? BroadCastType::Cable
                         : BroadCastType::Antenna;
        }
        void setRemoteMode(Remote &rt) const {
            if (mode_ == Mode::ON)
                rt.mode_ = (rt.mode_ == Remote::InputMode::Normal 
                            ? Remote::InputMode::Interactive
                            : Remote::InputMode::Normal);
            else
                throw TvOffException("Tv is off");
        }
        void setInput() { input_ = (input_ == Input::TV) ? Input::DVD : Input::TV; }
        void settings() const {
            std::cout << "Mode: " << (mode_ == Mode::ON ? "On" : "Off")
                      << "\nInput: " << (input_ == Input::TV ? "TV" : "DVD")
                      << "\nBroadcase Type: " << (broadcast_ == BroadCastType::Antenna ? "Antenna" : "Cable")
                      << "\nMaxChannel: " << maxChannel_
                      << "\nCurrent Channel: " << channel_
                      << "\nVolume : " << volume_
                      << '\n';
        }
    };

    // Remote Definitions
    inline void Remote::volup()   const { paired_tv_->volup(); }
    inline void Remote::voldown() const { paired_tv_->voldown(); }
    inline void Remote::toggleOnOff() const { paired_tv_->toggleOnOff(); }
    inline void Remote::channelUp()   const { paired_tv_->channelUp(); }
    inline void Remote::channelDown() const { paired_tv_->channelDown(); }
    inline void Remote::setChannel(int chan) const { 
        if (chan > Tv::MaxVal || chan < Tv::MinVal) 
            throw std::out_of_range("Channel out of range");
        paired_tv_->channel_ = chan; 
    }
    inline void Remote::setBroadCastType() const { paired_tv_->setBroadCastType(); }
    inline void Remote::setInput()         const { paired_tv_->setInput(); }
}

// Mock Program
int main() {
    Tv s42;
    std::cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.toggleOnOff();
    s42.channelUp();
    std::cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();

    Remote grey(&s42);
    grey.setChannel(10);
    grey.volup();
    grey.volup();

    std::cout << "\n42\" settings after using remote:\n";
    s42.settings();
    grey.showMode();
    s42.setRemoteMode(grey);
    grey.showMode();

    Tv s58(Tv::Mode::ON);
    s58.setBroadCastType();
    Remote(&s58).setChannel(28);
    std::cout << "\n58\" settings:\n";
    s58.settings();

    return 0;
}

