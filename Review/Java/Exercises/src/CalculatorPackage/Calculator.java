package CalculatorPackage;

import org.w3c.dom.ls.LSOutput;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;

import static java.lang.Character.isDigit;

public class Calculator {
    private JButton buttonPlus;
    private JButton a1Button;
    private JButton a2Button;
    private JButton a3Button;
    private JButton a4Button;
    private JButton a5Button;
    private JButton a6Button;
    private JButton a7Button;
    private JButton a8Button;
    private JButton a9Button;
    private JButton a0Button;
    private JButton buttonMinus;
    private JButton buttonProduct;
    private JButton buttonEqual;
    private JButton buttonDivide;
    private JTextPane result;
    private JPanel Calc;

    public int compute(String calculus) {
        int result = 0;
        StringBuilder buffer = new StringBuilder();
        Integer first_operand = null;
        Integer second_operand = null;
        char operation = '+';

        for (int i = 0; i < calculus.length(); i++) {
            if (isDigit(calculus.charAt(i))) {
                buffer.append(calculus.charAt(i));
            } else {
                if(first_operand == null) {
                    operation = calculus.charAt(i);
                    first_operand = Integer.parseInt(buffer.toString());
                    buffer = new StringBuilder();
                } else {
                    second_operand = Integer.parseInt(buffer.toString());
                }
            }
        }

        if (operation == '+') {
            result = first_operand + second_operand;
        } else if (operation == '*') {
            result = first_operand * second_operand;
        } else if (operation == '/') {
            result = first_operand / second_operand;
        } else if (operation == '-') {
            result = first_operand - second_operand;
        }
        return result;
    }

    public Calculator() {
        JFrame frame = new JFrame("Calculator");
        frame.add(Calc);
        frame.setSize(300, 220);
        frame.setVisible(true);

        a0Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a0Button.getText());
            }
        });

        a1Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a1Button.getText());
            }
        });

        a2Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a2Button.getText());
            }
        });

        a3Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a3Button.getText());
            }
        });

        a4Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a4Button.getText());
            }
        });

        a5Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a5Button.getText());
            }
        });

        a6Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a6Button.getText());
            }
        });

        a7Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a7Button.getText());
            }
        });

        a8Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a8Button.getText());
            }
        });

        a9Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + a9Button.getText());
            }
        });

        buttonPlus.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + buttonPlus.getText());
            }
        });

        buttonMinus.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + buttonMinus.getText());
            }
        });

        buttonProduct.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + buttonProduct.getText());
            }
        });

        buttonDivide.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + buttonDivide.getText());
            }
        });

        buttonEqual.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                result.setText(result.getText() + buttonEqual.getText());
                String calculus = result.getText();
                result.setText(Integer.toString(compute(calculus)));
            }
        });
    }
}