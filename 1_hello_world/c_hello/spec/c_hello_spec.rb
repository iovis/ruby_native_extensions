# frozen_string_literal: true

RSpec.describe CHello do
  context "hello" do
    it "is polite" do
      expect(described_class.hello("Erin")).to eq "Hello, Erin"
    end

    it "is inclusive" do
      expect(described_class.hello).to eq "Hello, World"
    end

    it "can get excited" do
      expect(described_class.hello!("dabidu")).to eq "HELLO, DABIDU!"
    end
  end

  context "fib" do
    it { expect(described_class.fib(5)).to eq 5 }
    it { expect(described_class.fib(7)).to eq 13 }
  end
end
